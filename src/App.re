open ReactNative;
open ReasonReact;
open ReactUtils;

let styles =
  Style.(
    StyleSheet.create({
      "body": style(~backgroundColor="#f0f", ()),
      "sectionContainer":
        style(
          ~marginTop=72.->dp,
          ~paddingHorizontal=24.->dp,
          ~marginHorizontal=72.->dp,
          (),
        ),
    })
  );

[@react.component]
let app = () =>
  <>
    <View style={styles##sectionContainer}>
      <Text> {toStr("yolo")} </Text>
      <TodoListScreen />
    </View>
  </>;