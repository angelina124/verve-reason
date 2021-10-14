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
let make = (~goToStore, ~uID, _) => {
  let (state, dispatch) =
    useReducer(
      (state, action) =>
        switch (action) {
        | TEXT_CHANGED(text) => {...state, text}
        | POINTS_CHANGED(points) => {...state, points}
        | ERROR_ADDING_REWARD => {...state, error: true}
        | _ => state
        },
      {error: false, canSubmit: true, text: "", points: defaultPoints},
    );
  <View style=styles##container>
    <TextInput
      placeholder="Buy a new watch"
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
          addReward(
            ~text=state.text,
            ~points=state.points,
            ~goToStore,
            ~userID=uID,
            ~dispatch,
          )
      }
    />
  </View>;
};