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
          ~fontSize=24.,
          ~color={
            colors.blueYonder;
          },
          (),
        ),
    })
  );

[@react.component]
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