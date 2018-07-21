let component = ReasonReact.statelessComponent("Search");

let make = (~updatePage, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <button
        className="btn"
        onClick=(_event => updatePage())
      >
        ("back" |. RR.string)
      </button>
      <p>
        ("Search" |. RR.string)
      </p>
    </div>
}