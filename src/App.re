open ReactNative;
open React;
open ReactUtils;
open Colors;
open Constants;
open Actions;
open Data;
open ReactUtils;
open Screens;
open Settings;

let windowDimensions = Dimensions.get(`window);
let height = windowDimensions.height;
let width = windowDimensions.width;

let styles =
  Style.(
    StyleSheet.create({
      "app":
        style(
          ~height=height->dp,
          ~width=width->dp,
          ~backgroundColor=colors.shore,
          (),
        ),
      "headerContainer":
        style(
          ~marginTop=56.->dp,
          ~padding=18.->dp,
          ~backgroundColor="#fff",
          ~opacity=0.8,
          (),
        ),
      "sectionContainer":
        style(
          ~marginTop=24.->dp,
          ~textAlign=`center,
          ~justifyContent=`center,
          (),
        ),
    })
  );

[@react.component]
let app = () => {
  let (state, dispatch) =
    useReducer(
      (state, action) =>
        switch (action) {
        | `TODOLIST => {...state, screen: `TODOLIST}
        | `ADD_TODO => {...state, screen: `ADD_TODO}
        | `ADD_REWARD => {...state, screen: `ADD_REWARD}
        | `STATS => {...state, screen: `STATS}
        | `STORE => {...state, screen: `STORE}
        | `LOGGED_IN(user) =>
          {screen: `STATS, user: Some(user)};
        | `ERROR => {...state, screen: `ERROR}
        | _ => {...state, screen: `NOT_FOUND}
        },
      {screen: `LOGIN, user: None},
    );

  let not_found =
    <View> <Text> {toStr("screen not found :(")} </Text> </View>;

  let stats =
    <View>
      <Button title="store" onPress={_ => dispatch(`STORE)} />
      <Button title="todos" onPress={_ => dispatch(`TODOLIST)} />
    </View>;
  <View style=styles##app>
    <View style=styles##headerContainer>
      <Header screen={state.screen} dispatch />
    </View>
    <View style=styles##sectionContainer>
      {
        switch (state.screen) {
        | `ADD_TODO => 
            <AddTodo 
              goToTodoList=(() => dispatch(`TODOLIST))
              tID= getDefaultTodoList(state.user)
              />
        | `ADD_REWARD => 
            <AddReward 
              goToStore=(() => dispatch(`STORE)) 
              uID= getID(state.user)
            />
        | `LOGIN =>
          <LoginScreen
            login=(
              (~username, ~password) =>
                AxiosUtils.login(~username, ~password, ~dispatch)
            )
            signup=(
              (~username, ~password) =>
                AxiosUtils.signup(~username, ~password, ~dispatch)
            )
          />
        | `STATS => stats
        | `STORE => 
            <StoreScreen 
              goToAddReward=(() => dispatch(`ADD_REWARD)) 
              uID= getID(state.user)
            />
        | `TODOLIST =>
          <TodoListScreen 
            goToAddTodo=(() => dispatch(`ADD_TODO)) 
            tID= getDefaultTodoList(state.user)
          />
        | _ => not_found
        }
      }
    </View>
    <View />
  </View>;
};