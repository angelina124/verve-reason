open ReactNative;
open React;
open Types;
open ReactUtils;
open AxiosUtils;
open Constants;

let styles =
  Style.(StyleSheet.create({"fetching": style(~alignItems=`center, ())}));

[@react.component]
let make = (~goToAddTodo) => {
  let (state: todoListScreen, dispatch) =
    useReducer(
      (state, action) =>
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
  </View>;
};