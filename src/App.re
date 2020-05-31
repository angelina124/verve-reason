open ReactNative;
open React;
open ReactUtils;
open Colors;
open Types;

let styles =
  Style.(
    StyleSheet.create({
      "header":
        style(
          ~textAlign=`center,
          ~fontSize=24.,
          ~color={
            colors.blueYonder;
          },
          (),
        ),
      "headerContainer":
        style(~padding=18.->dp, ~backgroundColor="#fff", ~opacity=0.8, ()),
      "sectionContainer":
        style(
          ~marginTop=64.->dp,
          ~textAlign=`center,
          ~justifyContent=`center,
          ~backgroundColor=colors.naplesYellow,
          (),
        ),
    })
  );

[@react.component]
let app = () => {
  let not_found =
    <View> <Text> {toStr("screen not found :(")} </Text> </View>;
  let (state, dispatch) =
    useReducer(
      (state, action) => {
        switch (action) {
        | TODOLIST => {screen: TODOLIST}
        | ADDTODO => {screen: ADDTODO}
        | _ => {screen: NOT_FOUND}
        }
      },
      {screen: TODOLIST},
    );
  <>
    <View style={styles##sectionContainer}>
      <View style={styles##headerContainer}>
        <Text style={styles##header}> {toStr("TODOS")} </Text>
        <Button title="Go to Todos" onPress={_ => dispatch(TODOLIST)} />
      </View>
    </View>
    <View>
      {switch (state.screen) {
       | TODOLIST => <TodoListScreen goToAddTodo={() => dispatch(ADDTODO)} />
       | ADDTODO => <AddTodo goToTodoList={() => dispatch(TODOLIST)} />
       | _ => not_found
       }}
    </View>
    <View />
  </>;
};