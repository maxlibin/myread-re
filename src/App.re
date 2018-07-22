[%bs.raw {|require('./App.css')|}];

type page =
  | Home
  | Search;

type state = {
  route: page
};

type action =
  | UpdatePage(page);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,

  initialState: () => {
    route: Home,
  },

  reducer: (action, _state) => {
    switch action {
    | UpdatePage(route) =>
      ReasonReact.Update({
        route: route
      });
    };
  },

  render: self => {
    <div className="app">
      (
        switch(self.state.route) {
        | Home => <Home updatePage=(() => self.send(UpdatePage(Search))) />
        | Search => <Search updatePage=(() => self.send(UpdatePage(Home))) />
        }
      )
    </div>;
  },
};
