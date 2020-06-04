open ReactNative;
open React;
<<<<<<< HEAD
open Types;
open ReactUtils;
open AxiosUtils;
=======
open Routes;
open Types;
open ReactUtils;
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
open Constants;

let styles =
  Style.(StyleSheet.create({"fetching": style(~alignItems=`center, ())}));

[@react.component]
let make = (~goToAddTodo) => {
<<<<<<< HEAD
  let (state: todoListScreen, dispatch) =
    useReducer(
      (state, action) =>
=======
  // declaration of react hooks
  let (state: todoListScreen, dispatch) =
    useReducer(
      (state, action) => {
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
        switch (action) {
        | FETCH_TODOS(ts) => {
            ...state,
            fetching: false,
            fetched: true,
            todoList: ts,
          }
        | FETCHING_TODOS => {...state, fetching: true}
        | ERROR_FETCHING_TODOS => {...state, fetching: false, error: true}
        | COMPLETE_TODO(completed) => {
            ...state,
            todoList:
              List.filter(
                (todo: todo) => todo._id != completed._id,
                state.todoList,
              ),
          }
        | ERROR_COMPLETING_TODO => {...state, fetching: false, error: true}
<<<<<<< HEAD
        },
      {todoList: [], fetching: false, fetched: false, error: false},
    );
  React.useEffect0(() => {
    dispatch(FETCHING_TODOS);
    Js.Global.setTimeout(() => fetchTodos(~todoID=tID, ~dispatch), 2000)
    |> ignore;
    Some(() => Js.log("updated"));
  });
  <View>
    {
      !state.fetching ?
        <View>
          <TodoList
            todoList={state.todoList}
            completeTodo={completeTodo(~dispatch)}
          />
          <Button title="Add todo" onPress={_ => goToAddTodo()} />
        </View> :
        <View style=styles##fetching>
          <Text> {toStr("fetching your awesome todos...")} </Text>
        </View>
    }
=======
        }
      },
      {todoList: [], fetching: false, fetched: false, error: false},
    );
  let fetchTodos = tID => {
    Js.Promise.(
      Axios.get(routes.todos ++ tID)
      |> then_(res => {
           let ts = res##data##todos;
           Js.log(ts);
           let todoList = Js.Array.reduceRight((a, t) => [t, ...a], [], ts);
           resolve(dispatch(FETCH_TODOS(todoList)));
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
    dispatch(FETCHING_TODOS);
    Js.Global.setTimeout(() => {fetchTodos(tID)}, 2000) |> ignore;
    Some(() => Js.log("updated"));
  });
  <View>
    {!state.fetching
       ? <View>
           <TodoList todoList={state.todoList} completeTodo />
           <Button title="Add todo" onPress={_ => goToAddTodo()} />
         </View>
       : <View style={styles##fetching}>
           <Text> {toStr("fetching your awesome todos...")} </Text>
         </View>}
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
  </View>;
};