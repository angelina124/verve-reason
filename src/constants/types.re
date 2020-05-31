type todo = {
  _id: string,
  text: string,
  points: int,
};

type todoAction =
  | FETCH_TODOS(list(todo))
  | FETCHING_TODOS
  | ERROR_FETCHING_TODOS
  | ADD_TODO(todo)
  | COMPLETE_TODO(todo)
  | ERROR_COMPLETING_TODO;

type screens =
  | TODOLIST
  | STATS
  | ADDTODO
  | STORE
  | NOT_FOUND;

type todoListScreen = {
  todolist: list(todo),
  fetching: bool,
  fetched: bool,
  error: bool,
};

type appScreen = {screen: React.element};

type states = {todoListScreen};