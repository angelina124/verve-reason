type todo = {
  text: string,
  points: int,
};

type action =
  | FETCH_TODOS(list(todo))
  | FETCHING_TODOS
  | ERROR_FETCHING_TODOS
  | ADD_TODO(todo);

type todoListScreen = {
  todos: list(todo),
  fetching: bool,
  fetched: bool,
  error: bool,
};

type states = {todoListScreen};