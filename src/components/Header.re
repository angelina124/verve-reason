open ReactNative;
open ReactUtils;
open Colors;
open Types;

let styles =
  Style.(
    StyleSheet.create({
      "header":
        style(
          ~textAlign=`center,
<<<<<<< HEAD
          ~alignItems=`center,
          ~fontSize=24.,
          ~color=colors.blueYonder,
          (),
        ),
      "nav": style(),
=======
          ~fontSize=24.,
          ~color={
            colors.blueYonder;
          },
          (),
        ),
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
    })
  );

[@react.component]
<<<<<<< HEAD
let make = (~screen, ~dispatch) =>
  switch (screen) {
  | STATS =>
    <View> <Text style=styles##header> {toStr("STATS")} </Text> </View>
  | TODOLIST =>
    <View style=styles##nav>
      <Button title="back" onPress=(_ => dispatch(STATS)) />
      <Text style=styles##header> {toStr("TODOS")} </Text>
    </View>
  | ADDTODO =>
    <View> <Text style=styles##header> {toStr("TODOS")} </Text> </View>
  | STORE =>
    <View style=styles##nav>
      <Button title="back" onPress=(_ => dispatch(STATS)) />
      <Text style=styles##header> {toStr("STORE")} </Text>
    </View>
  | _ =>
    <View style=styles##nav>
      <Button title="back" onPress=(_ => dispatch(STATS)) />
      <Text style=styles##header> {toStr("NOT FOUND")} </Text>
    </View>
  };
=======
let make = (~screen) => {
  switch (screen) {
  | STATS =>
    <View> <Text style={styles##header}> {toStr("STATS")} </Text> </View>
  | TODOLIST =>
    <View> <Text style={styles##header}> {toStr("TODOS")} </Text> </View>
  | ADDTODO =>
    <View> <Text style={styles##header}> {toStr("TODOS")} </Text> </View>
  | STORE =>
    <View> <Text style={styles##header}> {toStr("STORE")} </Text> </View>
  | _ => <Text style={styles##header}> {toStr("NOT FOUND")} </Text>
  };
};
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7
