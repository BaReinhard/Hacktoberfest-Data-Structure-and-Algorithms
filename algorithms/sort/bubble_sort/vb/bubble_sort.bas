Option Explicit
'VB6 Specific
Private Sub bubble_sort()
Dim i As Integer
Dim j As Integer
Dim k As Integer
Dim array_unsorted(1001) As String
Dim array_sorted(1001) As String
Dim temp As String
Dim swapped As Boolean
    i = 1000
    j = 0
    Do
        swapped = False
        For j = 1 To i - 1
            If LCase(array_unsorted(j)) > LCase(array_unsorted(j + 1)) Then
                temp = array_unsorted(j)
                array_unsorted(j) = array_unsorted(j + 1)
                array_unsorted(j + 1) = temp
                swapped = True
            End If
        Next j
        i = i - 1
    Loop Until Not swapped
    For k = 1 To 1000
        array_sorted(k) = array_unsorted(k)
    Next k
End Sub


