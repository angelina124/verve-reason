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
        | TODOLIST => {...state, screen: <TodoListScreen />}
        | _ => {...state, screen: not_found}
        }
      },
      {screen: <TodoListScreen />},
    );
  <>
    <View style={styles##sectionContainer}>
      <View style={styles##headerContainer}>
        <Text style={styles##header}> {toStr("TODOS")} </Text>
        <Button title="Go to Todos" onPress={_ => dispatch(TODOLIST)} />
        <Button title="Go to not found" onPress={_ => dispatch(NOT_FOUND)} />
      </View>
    </View>
    <View> {state.screen} </View>
    <View />
  </>;
};