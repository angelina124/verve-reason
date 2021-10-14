open ReactNative;
open React;
open Actions;
open Screens;
open AxiosUtils;
open Constants;
open Colors;

let windowDimensions = Dimensions.get(`window);
let windowWidth = windowDimensions.width;

let styles =
  Style.(
    StyleSheet.create({
      "container": style(~display=`flex, ~alignItems=`center, ()),
      "textInput":
        style(
          ~width=(0.6 *. windowWidth)->dp,
          ~borderColor=colors.blueYonder,
          ~borderWidth=2.,
          ~borderRadius=5.,
          ~padding=8.->dp,
          ~alignItems=`center,
          ~alignSelf=`center,
          ~fontSize=18.,
          ~marginBottom=16.->dp,
          (),
        ),
    })
  );

[@react.component]
let make = (~goToTodoList, ~tID, _) => {
  let (state, dispatch) =
    useReducer(
      (state, action) =>
        switch (action) {
        | TEXT_CHANGED(text) => {...state, text}
        | ERROR_ADDING_TODO => {...state, error: true}
        | _ => state
        },
      {error: false, canSubmit: true, text: "", points: defaultPoints},
    );
  <View style=styles##container>
    <TextInput
      style=styles##textInput
      onChangeText={text => dispatch(TEXT_CHANGED(text))}
    />
    <TextInput
      placeholder="0"
      style=styles##textInput
      keyboardType=`numberPad
      onChangeText={points => dispatch(POINTS_CHANGED(int_of_string(points)))}
    />
    <Button
      title="Submit"
      onPress={
        _ =>
          addTodo(
            ~text=state.text,
            ~points=state.points,
            ~goToTodoList,
            ~todoListID=tID,
            ~dispatch,
          )
      }
    />
  </View>;
};