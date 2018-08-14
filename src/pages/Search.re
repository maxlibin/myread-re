let component = ReasonReact.statelessComponent("Search");

let make = (~updatePage, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <a
        href="/"
        className="btn"
      >
        ("back" |. RR.string)
      </a>
      <p>
        ("Search" |. RR.string)
      </p>
    </div>
}