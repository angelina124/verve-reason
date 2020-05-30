open ReactNative;
open React;
open ReactUtils;
open ReasonReact;
open Axios;

open Routes;
open Types;

let userID = "5ed2787cd20bf24e921e38d0";

[@react.component]
let make = () => {
  // declaration of react hooks
  let (todos, updated) = React.useState(() => "Todo app?");
  let (state, dispatch) =
    useReducer(
      (state, action) => {
        switch (action) {
        | FETCH_TODOS(todos) => {
            ...state,
            fetching: false,
            fetched: true,
            todos,
          }
        | FETCHING_TODOS => {...state, fetching: true}
        | ERROR_FETCHING_TODOS => {...state, fetching: false, error: true}
        | ADD_TODO(todo) => {...state, todos: [todo, ...state.todos]}
        }
      },
      {todos: [], fetching: false, fetched: false, error: false},
    );
  let fetchTodos = userID => {
    Js.Promise.(
      Axios.get(routes.todos ++ userID)
      |> then_(res => {
           let ts = res##data##todos;
           let todos = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
           resolve(dispatch(FETCH_TODOS(todos)));
         })
      |> catch(err => {
           Js.log(err);
           resolve(dispatch(ERROR_FETCHING_TODOS));
         })
      |> ignore
    );
  };
  React.useEffect0(() => {
    Js.Global.setTimeout(() => {fetchTodos(userID)}, 2000) |> ignore;
    Some(() => Js.log("updated"));
  });
  <View> <TodoList todos={state.todos} /> </View>;
};