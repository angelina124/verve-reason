type todo = {
  _id: string,
  text: string,
  points: int,
};

type action =
  | FETCH_TODOS(list(todo))
  | FETCHING_TODOS
  | ERROR_FETCHING_TODOS
  | ADD_TODO(todo)
  | COMPLETE_TODO(todo)
  | ERROR_COMPLETING_TODO;

type todoListScreen = {
  todolist: list(todo),
  fetching: bool,
  fetched: bool,
  error: bool,
};

type states = {todoListScreen};