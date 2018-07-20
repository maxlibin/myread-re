let component = ReasonReact.statelessComponent("Home");

let make = (~updatePage=?, _children) => {
  ...component,
  render: _self =>
    <div className="home">
      <div className="list-books">
        <div className="list-books-title">
          <h1>{"MyReads" |> RR.string}</h1>
          <p>{"Udacity React nanodegree MyReads project" |> RR.string}</p>
          <div
            className="btn"
          >
            {"Add a book" |> RR.string}
          </div>
        </div>
      </div>
    </div>
}
