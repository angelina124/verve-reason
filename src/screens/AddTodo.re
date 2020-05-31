open ReactNative;
open React;
open Routes;
open Types;
open ReactUtils;
open Constants;
open Colors;

let userID = "5ed2787cd20bf24e921e38d0";

let windowDimensions = Dimensions.get(`window);
let windowWidth = windowDimensions##width;

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
          (),
        ),
    })
  );

[@react.component]
let make = (~goToTodoList: unit => unit) => {
  // declaration of react hooks
  let (state, dispatch) =
    useReducer(
      (state, action) => {
        switch (action) {
        | TEXT_CHANGED(text) => {...state, text}
        | ERROR_ADDING_TODO => {...state, error: true}
        | _ => state
        }
      },
      {error: false, canSubmit: true, text: "", points: defaultPoints},
    );
  let addTodo = (~text: string, ~points: int) => {
    Js.Promise.(
      Axios.postData(
        routes.addTodo ++ userID,
        newTodoToObject({text, points}),
      )
      |> then_(res => {resolve(dispatch(ADD_TODO(res##data)))})
      |> catch(_ => resolve(dispatch(ERROR_ADDING_TODO)))
      |> ignore
    );
  };
  <View style={styles##container}>
    <TextInput
      style={styles##textInput}
      onChangeText={text => dispatch(TEXT_CHANGED(text))}
    />
    <Button
      title="Submit"
      onPress={_ => {
        addTodo(~text=state.text, ~points=state.points);
        goToTodoList();
      }}
    />
  </View>;
};