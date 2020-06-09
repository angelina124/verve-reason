open Data;

type mode =
  | DEVELOP
  | PRODUCTION;

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
  | ADD_REWARD(reward)
  | ERROR_ADDING_REWARD
  | TEXT_CHANGED(string);

type screens = [
  | `TODOLIST
  | `STATS
  | `ADD_TODO
  | `ADD_REWARD
  | `STORE
  | `LOGIN
  | `ERROR
  | `NOT_FOUND
];

type loginAction =
  | USERNAME_UPDATED(string)
  | PASSWORD_UPDATED(string)
  | PASSWORD_REPEAT_UPDATED(string)
  | ERROR_SUBMITTING
  | TOGGLE_LOGIN;

type userAction = [ | `LOGGED_IN(user) | `ERROR];

type appAction = [ screens | userAction];