open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "body": style(~backgroundColor="#f0f", ()),
      "sectionContainer":
        style(~marginTop=32.->dp, ~paddingHorizontal=24.->dp, ()),
    })
  );

[@react.component]
let app = () =>
  <View style=styles##sectionContainer>
    <Text style=styles##body> {ReasonReact.string("Testing123!")} </Text>
    <TodoListScreen />
  </View>;