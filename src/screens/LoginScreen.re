open ReactNative;
open React;
open Routes;
open Actions;
open Data;
open Screens;
open Settings;
open Constants;
open ReactUtils;
open AxiosUtils;
open Constants;
open Colors;
open Validation;

let windowDimensions = Dimensions.get(`window);
let windowWidth = windowDimensions##width;

let styles =
  Style.(
    StyleSheet.create({
      "container": style(~display=`flex, ~alignItems=`center, ()),
      "textInput":
        style(
          ~width=(0.6 *. windowWidth)->dp,
          ~borderColor=colors.blueYonder,
          ~borderWidth=2.,
          ~borderRadius=5.,
          ~marginVertical=8.->dp,
          ~padding=8.->dp,
          ~alignItems=`center,
          ~alignSelf=`center,
          ~fontSize=18.,
          (),
        ),
    })
  );

[@react.component]
let make = (~login, ~signup, _) => {
  let (state: loginScreen, dispatch) =
    useReducer(
      (state, action) =>
        switch (action) {
        | USERNAME_UPDATED(username) => {
            ...state,
            username,
            canSubmit: validUsername(~username),
          }
        | PASSWORD_UPDATED(password) => {
            ...state,
            password,
            canSubmit: validPassword(~password),
          }
        | PASSWORD_REPEAT_UPDATED(passwordRepeat) => {
            ...state,
            passwordRepeat,
            canSubmit:
              validPassword(~password=state.password)
              && state.password == passwordRepeat,
          }
        | ERROR_SUBMITTING => {...state, error: true}
        | TOGGLE_LOGIN => {...state, isLogin: !state.isLogin}
        },
      {
        username: "",
        password: "",
        passwordRepeat: "",
        canSubmit: false,
        error: false,
        isLogin: true,
      },
    );
  let submit = () =>
    if (!state.canSubmit) {
      Js.log("oop");
      Js.log(state);
      dispatch(ERROR_SUBMITTING);
    } else if (state.isLogin) {
      login(~username=state.username, ~password=state.password);
    } else {
      signup(~username=state.username, ~password=state.password);
    };
  <View style=styles##container>
    <TextInput
      style=styles##textInput
      onChangeText={username => dispatch(USERNAME_UPDATED(username))}
      textContentType=`username
    />
    <TextInput
      style=styles##textInput
      onChangeText={password => dispatch(PASSWORD_UPDATED(password))}
      textContentType=`password
    />
    {
      state.isLogin ?
        React.null :
        <TextInput
          style=styles##textInput
          onChangeText={
            password => dispatch(PASSWORD_REPEAT_UPDATED(password))
          }
          textContentType=`password
        />
    }
    <Button
      title={state.isLogin ? "or sign up" : "or log in"}
      onPress={_ => dispatch(TOGGLE_LOGIN)}
    />
    <Button title="submit" onPress={_ => submit()} />
  </View>;
};