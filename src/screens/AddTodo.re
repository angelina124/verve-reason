open ReactNative;
open React;
open Routes;
open Types;
open ReactUtils;
<<<<<<< HEAD
open AxiosUtils;
=======
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
open Constants;
open Colors;

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
<<<<<<< HEAD
=======
  let addTodo = (~text: string, ~points: int) => {
    Js.Promise.(
      Axios.postData(routes.addTodo ++ tID, newTodoToObject({text, points}))
      |> then_(res => {resolve(dispatch(ADD_TODO(res##data)))})
      |> catch(_ => resolve(dispatch(ERROR_ADDING_TODO)))
      |> ignore
    );
  };
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
  <View style={styles##container}>
    <TextInput
      style={styles##textInput}
      onChangeText={text => dispatch(TEXT_CHANGED(text))}
    />
    <Button
      title="Submit"
      onPress={_ => {
<<<<<<< HEAD
          addTodo(~text=state.text, 
          ~points=state.points,
          ~goToTodoList=goToTodoList, 
          ~todoID=tID, 
          ~dispatch=dispatch)
        }
      }
=======
        addTodo(~text=state.text, ~points=state.points);
        goToTodoList();
      }}
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
    />
  </View>;
};