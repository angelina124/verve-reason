open ReactNative;
open ReactUtils;
open Colors;

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
let app = () =>
  <>
    <View style={styles##sectionContainer}>
      <View style={styles##headerContainer}>
        <Text style={styles##header}> {toStr("TODOS")} </Text>
      </View>
      <View> <TodoListScreen /> </View>
    </View>
  </>;