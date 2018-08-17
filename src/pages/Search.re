let component = ReasonReact.statelessComponent("Search");

let make = (~updatePage, _children) => {
  ...component,
  render: (_self) =>
    <div className="search-books">
      <div className="search-books-bar">
        <a
          href="/"
          className="close-search"
        >
          ("Close" |. RR.string)
        </a>
        <input
          name="searchQuery"
          type_="text"
          placeholder="Search by title or author"
        />
      </div>
      <div className="search-books-results">
        <p>{"Enter something in above search box and press enter to search for your favorite books" |> RR.string}</p>
      </div>
    </div>
}