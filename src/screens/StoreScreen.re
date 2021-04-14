open ReactNative;
open React;
open Routes;
open Actions;
open Data;
open Screens;
open Settings;
open ReactUtils;
open AxiosUtils;
open Constants;

let styles =
  Style.(StyleSheet.create({"fetching": style(~alignItems=`center, ())}));

[@react.component]
let make = (~goToAddReward, _) => {
  let (state: storeScreen, dispatch) =
    useReducer(
      (state, action) =>
        switch (action) {
        | FETCHED_REWARDS(ts) => {
            ...state,
            fetching: false,
            fetched: true,
            rewardList: ts,
          }
        | FETCHING_REWARDS => {...state, fetching: true}
        | ERROR_FETCHING_REWARDS => {...state, fetching: false, error: true}
        },
      {rewardList: [], fetching: false, fetched: false, error: false},
    );
  React.useEffect0(() => {
    dispatch(FETCHING_REWARDS);
    Js.Global.setTimeout(() => fetchRewards(~uID, ~dispatch), 2000) |> ignore;
    Some(() => Js.log("updated"));
  });
  <View>
    {
      !state.fetching ?
        <View>
          <Store rewardList={Some(state.rewardList)} />
          <Button title="Add reward" onPress={_ => goToAddReward()} />
        </View> :
        <View style=styles##fetching>
          <Text> {toStr("fetching your awesome rewards...")} </Text>
        </View>
    }
  </View>;
};