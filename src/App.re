[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,

  render: _self => {
    <div className="app">
      <Home />
    </div>;
  },
};
