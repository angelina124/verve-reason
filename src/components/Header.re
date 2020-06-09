open ReactNative;
open ReactUtils;
open Colors;
open Actions;
open Data;
open Screens;
open Settings;

let styles =
  Style.(
    StyleSheet.create({
      "header":
        style(
          ~textAlign=`center,
          ~alignItems=`center,
          ~fontSize=24.,
          ~color=colors.blueYonder,
          (),
        ),
      "nav": style(),
    })
  );

[@react.component]
let make = (~screen, ~dispatch, _) =>
  switch (screen) {
  | `STATS =>
    <View> <Text style=styles##header> {toStr("STATS")} </Text> </View>
  | `LOGIN =>
    <View> <Text style=styles##header> {toStr("LOG IN")} </Text> </View>
  | `TODOLIST =>
    <View style=styles##nav>
      <Button title="back" onPress=(_ => dispatch(`STATS)) />
      <Text style=styles##header> {toStr("TODOS")} </Text>
    </View>
  | `ADD_TODO =>
    <View> <Text style=styles##header> {toStr("TODOS")} </Text> </View>
  | `STORE =>
    <View style=styles##nav>
      <Button title="back" onPress=(_ => dispatch(`STATS)) />
      <Text style=styles##header> {toStr("STORE")} </Text>
    </View>
  | _ =>
    <View style=styles##nav>
      <Button title="back" onPress=(_ => dispatch(`STATS)) />
      <Text style=styles##header> {toStr("NOT FOUND")} </Text>
    </View>
  };