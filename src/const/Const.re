type shelfs = {
 title: string,
 key: string
};

type bookShelfs = list(shelfs);

let bookshelfs = [
  { title: "Currently Reading", key: "currentlyReading" },
  { title: "Want To Read", key: "wantToRead" },
  { title: "Read", key: "read" },
];