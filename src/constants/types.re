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

type todosAction =
  | FETCH_TODOS(list(todo))
  | FETCHING_TODOS
  | ERROR_FETCHING_TODOS
  | COMPLETE_TODO(todo)
  | ERROR_COMPLETING_TODO;

type storeAction =
  | FETCH_REWARDS(list(reward))
  | FETCHING_REWARDS
  | ERROR_FETCHING_REWARDS;

type addAction =
  | ADD_TODO(todo)
  | ERROR_ADDING_TODO
  | TEXT_CHANGED(string);

type screens =
  | TODOLIST
  | STATS
  | ADDTODO
  | STORE
  | NOT_FOUND;

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

type appScreen = {screen: screens};

type addTodoScreen = {
  error: bool,
  canSubmit: bool,
  text: string,
  points: int,
};

type states = {
  todoListScreen,
  appScreen,
  addTodoScreen,
  storeScreen,
};