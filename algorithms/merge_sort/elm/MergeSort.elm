module Main exposing (..)

import Html exposing (text)


-- MergeSort


mergeSort : List comparable -> List comparable
mergeSort list =
    case list of
        [] ->
            list

        [ _ ] ->
            list

        _ ->
            let
                ( xs, ys ) =
                    split list
            in
                merge (mergeSort xs) (mergeSort ys)


split : List a -> ( List a, List a )
split list =
    case list of
        [] ->
            ( [], [] )

        x :: rest ->
            let
                ( xs, ys ) =
                    split rest
            in
                ( ys, x :: xs )


merge : List comparable -> List comparable -> List comparable
merge xs ys =
    case ( xs, ys ) of
        ( x :: xBack, y :: yBack ) ->
            if (x < y) then
                x :: merge xBack ys
            else
                y :: merge xs yBack

        ( rest, [] ) ->
            rest

        ( [], rest ) ->
            rest



-- Example


sample =
    [ 2000, 24, 1, 2, 6, 4, 12, 15, 22, 2, 33, 101, 75 ]


main =
    (mergeSort sample)
        |> (text << toString)
