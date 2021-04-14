type id = string;

type mode =
  | DEVELOP
  | PRODUCTION;

type todo = {
  _id: string,
  text: string,
  points: int,
};

type reward = {
  _id: string,
  text: string,
  points: int,
};

type new_todo = {
  text: string,
  points: int,
};

type user = {
  _id: string,
  username: string,
  todoLists: list(list(todo)),
  rewards: list(reward),
};

type loginFields = {
  username: string,
  password: string,
};

type todosAction =
  | FETCHED_TODOS(list(todo))
  | FETCHING_TODOS
  | ERROR_FETCHING_TODOS
  | COMPLETED_TODO(todo)
  | ERROR_COMPLETING_TODO;

type storeAction =
  | FETCHED_REWARDS(list(reward))
  | FETCHING_REWARDS
  | ERROR_FETCHING_REWARDS;

type addAction =
  | ADD_TODO(todo)
  | ERROR_ADDING_TODO
  | TEXT_CHANGED(string);

type screens = [
  | `TODOLIST
  | `STATS
  | `ADD_TODO
  | `STORE
  | `LOGIN
  | `ERROR
  | `NOT_FOUND
];

type loginAction =
  | USERNAME_UPDATED(string)
  | PASSWORD_UPDATED(string)
  | ERROR_SUBMITTING
  | TOGGLE_LOGIN;

type userAction = [ | `LOGGED_IN(user) | `ERROR];

type appAction = [ screens | userAction];

type loginScreen = {
  username: string,
  password: string,
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