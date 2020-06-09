open Data;
open Actions;

type loginScreen = {
  username: string,
  password: string,
  passwordRepeat: string,
  canSubmit: bool,
  error: bool,
  isLogin: bool,
};

type todoListScreen = {
  todoList: list(todo),
  fetching: bool,
  fetched: bool,
  error: bool,
};

type storeScreen = {
  rewardList: list(reward),
  fetching: bool,
  fetched: bool,
  error: bool,
};

type addTodoScreen = {
  error: bool,
  canSubmit: bool,
  text: string,
  points: int,
};

type appScreen = {
  screen: screens,
  user: option(user),
};

type state = {
  todoListScreen,
  appScreen,
  addTodoScreen,
  loginScreen,
  storeScreen,
};