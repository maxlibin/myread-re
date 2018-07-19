let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="home">
      <div className="list-books">
        <div className="list-books-title">
          <h1>{ReasonReact.string("MyReads")}</h1>
          <p>{ReasonReact.string("Udacity React nanodegree MyReads project")}</p>
          <a href="/search" className="btn">
            {ReasonReact.string("Add a book")}
          </a>
        </div>
      </div>
    </div>
}
