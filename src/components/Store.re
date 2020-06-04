open ReactNative;
open ReasonReact;
open ReactUtils;
open Types;

let windowDimensions = Dimensions.get(`window);
let windowWidth = windowDimensions##width;

let styles =
  Style.(
    StyleSheet.create({
      "text": style(~width=(0.5 *. windowWidth)->dp, ()),
      "points": style(~width=(0.1 *. windowWidth)->dp, ()),
      "rewardContainer":
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
      "rewardList": style(~marginTop=32.->dp, ~alignItems=`center, ()),
    })
  );

[@react.component]
let make = (~rewardList: option(list(reward))=?, _) => {
  switch (rewardList) {
  | Some(rewards) =>
    <View style={styles##rewardList}>
      {List.mapi(
         (i, reward: reward) => {
           <View key={string_of_int(i)} style={styles##rewardContainer}>
             <View style={styles##points}>
               <Text> {string_of_int(reward.points) |> toStr} </Text>
             </View>
             <View style={styles##text}>
               <Text> {toStr(reward.text)} </Text>
             </View>
           </View>
         },
         rewards,
       )
       |> Array.of_list
       |> array}
    </View>
  | None => <View> <Text> {toStr("No rewards here!")} </Text> </View>
  };
};