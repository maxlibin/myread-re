let component = ReasonReact.statelessComponent("Bookshelf");

let make = (~title:string="", ~books, _children) => {
  ...component,
  render: (_self) => {
    <div className="bookshelf">
      <h2 className="bookshelf-title">
        <span>
          (title |> RR.string)
        </span>
      </h2>
      <div className="bookshelf-books">
        /* {books.length === 0 ? (
          <div className={"bookshelfLoading"}>
            <span className="loader" /> Loading...
          </div>
        ) : (
          <ol className="books-grid">
            {books.map((book) => (
              <BooksList
                key={book.id}
                {...book}
                updateBooks={updateBooks}
              />
            ))}
          </ol>
        )} */
        <ol className="books-grid">
          /* books |> List.map(book => {
            <div className="book">
              <div className="book-top">
                <div className="book-cover" style=style></div>
                <div className="book-shelf-changer">
                </div>
              </div>
            </div>
          }) */
        </ol>
      </div>
    </div>
  }
}