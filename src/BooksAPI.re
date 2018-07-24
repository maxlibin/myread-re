
let api = "https://reactnd-books-api.udacity.com";

let getAll = Js.Promise.(
    Fetch.fetchWithInit(
      api ++ "/books",
      Fetch.RequestInit.make(
        ~method_=Get,
        ~headers=Fetch.HeadersInit.make({
          "Accept": "application/json",
          "Authorization": "myreadrelocal123123"
        }),
        ()
      )
    )
    |> then_(Fetch.Response.json |> resolve)
);