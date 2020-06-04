<<<<<<< HEAD
open Types

let mode = PRODUCTION

let path = 
switch (mode) {
  | PRODUCTION => "https://verve-api.herokuapp.com/api/"
  | DEVELOP => "http://localhost:3000/api/"
}
=======
let path = "http://localhost:3000/api/";
>>>>>>> f3185f45afc5b08d547916c57cce2badf78de4c7

type todo_route = string;
type user_route = string;
type reward_route = string;

type routes = {
  todos: todo_route,
  completeTodo: todo_route,
  addTodo: todo_route,
  addReward: reward_route,
  rewards: reward_route,
  user: user_route,
  login: user_route,
};

let routes = {
  todos: path ++ "todos/",
  completeTodo: path ++ "todos/complete/",
  addTodo: path ++ "todos/",
  rewards: path ++ "rewards/",
  addReward: path ++ "rewards/",
  user: path ++ "users/",
  login: path ++ "users/login",
};