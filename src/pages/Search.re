let component = ReasonReact.statelessComponent("Search");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <p>
      ("Search" |. RR.string)
    </p>
  }
}