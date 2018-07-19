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

  render: ({state}) => {
    <div className="app">
      (
        switch(state.route) {
        | Home => <Home updatePage=(() => self.send(UpdatePage)) />
        | _ =>
          <div>
            ("Not found" |> RR.string)
          </div>
        }
      )
    </div>;
  },
};
