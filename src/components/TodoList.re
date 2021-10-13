open ReactNative;
open ReasonReact;
open ReactUtils;
open Actions;
open Data;
open Screens;
open Settings;

let windowDimensions = Dimensions.get(`window);
let windowWidth = windowDimensions.width;

let styles =
  Style.(
    StyleSheet.create({
      "delIcon":
        style(
          ~width=(0.08 *. windowWidth)->dp,
          ~height=(0.08 *. windowWidth)->dp,
          ~resizeMode=`stretch,
          (),
        ),
      "text": style(~width=(0.5 *. windowWidth)->dp, ()),
      "points": style(~width=(0.1 *. windowWidth)->dp, ()),
      "todoContainer":
        style(
          ~width=(0.9 *. windowWidth)->dp,
          ~minWidth=100.->dp,
          ~marginBottom=8.->dp,
          ~padding=24.->dp,
          ~display=`flex,
          ~flexDirection=`row,
          ~alignItems=`center,
          ~backgroundColor="#fff",
          ~opacity=0.8,
          ~borderRadius=10.,
          (),
        ),
      "todoList": style(~marginTop=32.->dp, ~alignItems=`center, ()),
    })
  );

let delIconPath = Packager.require("../../assets/todos/delete.png");

module DelIcon = {
  [@react.component]
  let make = _ =>
    <Image
      source={Image.Source.fromRequired(delIconPath)}
      resizeMethod=`scale
      style=styles##delIcon
    />;
};

[@react.component]
let make = (~completeTodo, ~todoList, _) =>
  switch (todoList) {
  | Some(todos) =>
    <View style=styles##todoList>
      {
        List.mapi(
          (i, todo: todo) =>
            <View key={string_of_int(i)} style=styles##todoContainer>
              <View style=styles##points>
                <Text> {string_of_int(todo.points) |> toStr} </Text>
              </View>
              <View style=styles##text>
                <Text> {toStr(todo.text)} </Text>
              </View>
              <TouchableOpacity onPress={_ => completeTodo(~todoID=todo._id)}>
                <DelIcon />
              </TouchableOpacity>
            </View>,
          todos,
        )
        |> Array.of_list
        |> array
      }
    </View>
  | None => <View> <Text> {toStr("No todos here!")} </Text> </View>
  };