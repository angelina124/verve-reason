open ReactNative;
open React;
open Routes;
open Types;

let userID = "5ed2787cd20bf24e921e38d0";

[@react.component]
let make = (~goToAddTodo) => {
  // declaration of react hooks
  let (state, dispatch) =
    useReducer(
      (state, action) => {
        switch (action) {
        | FETCH_TODOS(ts) => {
            ...state,
            fetching: false,
            fetched: true,
            todolist: ts,
          }
        | FETCHING_TODOS => {...state, fetching: true}
        | ERROR_FETCHING_TODOS => {...state, fetching: false, error: true}
        | COMPLETE_TODO(completed) => {
            ...state,
            todolist:
              List.filter(todo => todo._id != completed._id, state.todolist),
          }
        | ERROR_COMPLETING_TODO => {...state, fetching: false, error: true}
        }
      },
      {todolist: [], fetching: false, fetched: false, error: false},
    );
  let fetchTodos = userID => {
    Js.Promise.(
      Axios.get(routes.todos ++ userID)
      |> then_(res => {
           let ts = res##data##todos;
           Js.log(ts);
           let todolist = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
           resolve(dispatch(FETCH_TODOS(todolist)));
         })
      |> catch(err => {
           Js.log(err);
           resolve(dispatch(ERROR_FETCHING_TODOS));
         })
      |> ignore
    );
  };
  let completeTodo = (~todoID: string) => {
    Js.Promise.(
      Axios.post(routes.completeTodo ++ todoID)
      |> then_(res => {
           let todo = res##data##todoDoc;
           resolve(dispatch(COMPLETE_TODO(todo)));
         })
      |> catch(_ => resolve(dispatch(ERROR_COMPLETING_TODO)))
      |> ignore
    );
  };
  React.useEffect0(() => {
    Js.Global.setTimeout(() => {fetchTodos(userID)}, 2000) |> ignore;
    Some(() => Js.log("updated"));
  });
  <View>
    <TodoList todolist={state.todolist} completeTodo />
    <Button title="Add todo" onPress={_ => goToAddTodo()} />
  </View>;
};