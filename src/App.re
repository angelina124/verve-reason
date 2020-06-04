open ReactNative;
open React;
open ReactUtils;
open Colors;
open Types;

let windowDimensions = Dimensions.get(`window);
let height = windowDimensions##height;
let width = windowDimensions##width;

let styles =
  Style.(
    StyleSheet.create({
      "app":
        style(
          ~height=height->dp,
          ~width=width->dp,
          ~backgroundColor=colors.naplesYellow,
          (),
        ),
      "headerContainer":
        style(
          ~marginTop=56.->dp,
          ~padding=18.->dp,
          ~backgroundColor="#fff",
          ~opacity=0.8,
          (),
        ),
      "sectionContainer":
        style(
          ~marginTop=24.->dp,
          ~textAlign=`center,
          ~justifyContent=`center,
          (),
        ),
    })
  );

[@react.component]
let app = () => {
  let (state, dispatch) =
    useReducer(
<<<<<<< HEAD
      (state, action) =>
=======
      (state, action) => {
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
        switch (action) {
        | TODOLIST => {screen: TODOLIST}
        | ADDTODO => {screen: ADDTODO}
        | STATS => {screen: STATS}
        | STORE => {screen: STORE}
        | _ => {screen: NOT_FOUND}
<<<<<<< HEAD
        },
=======
        }
      },
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
      {screen: STATS},
    );
  let not_found =
    <View> <Text> {toStr("screen not found :(")} </Text> </View>;
  let stats =
    <View>
      <Button title="store" onPress={_ => dispatch(STORE)} />
      <Button title="todos" onPress={_ => dispatch(TODOLIST)} />
    </View>;
<<<<<<< HEAD
  <View style=styles##app>
    <View style=styles##headerContainer>
      <Header screen={state.screen} dispatch />
    </View>
    <View style=styles##sectionContainer>
      {
        switch (state.screen) {
        | TODOLIST => <TodoListScreen goToAddTodo=(() => dispatch(ADDTODO)) />
        | ADDTODO => <AddTodo goToTodoList=(() => dispatch(TODOLIST)) />
        | STORE => <StoreScreen />
        | STATS => stats
        | _ => not_found
        }
      }
=======
  <View style={styles##app}>
    <View style={styles##headerContainer}>
      <Header screen={state.screen} />
    </View>
    <View style={styles##sectionContainer}>
      {switch (state.screen) {
       | TODOLIST => <TodoListScreen goToAddTodo={() => dispatch(ADDTODO)} />
       | ADDTODO => <AddTodo goToTodoList={() => dispatch(TODOLIST)} />
       | STORE => <StoreScreen />
       | STATS => stats
       | _ => not_found
       }}
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
    </View>
    <View />
  </View>;
};