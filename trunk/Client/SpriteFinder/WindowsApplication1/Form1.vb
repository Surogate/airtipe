
Imports System.Drawing
Imports System.IO
Public Class Form1
    Public bit As New List(Of Bitmap)

    Public i As Integer

    Public sprites As New List(Of SpriteInfo)
    Public b As Bitmap
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        i = 0
        Dim image As Image
        Dim files As String() = Directory.GetFiles("F:\Bureau\epitech\atype\sprites")
        files(1) = "F:\Bureau\epitech\atype\Mon Rtype\RtypeClient\RtypeClient\sprites\spritespng\r-typesheet5.png"
        image = image.FromFile(files(1))
        bit.Add(New Bitmap(image))
        b = bit(0)
        RichTextBox1.Text &= files(0) & " " & b.Width & " x " & b.Height & vbNewLine


        Dim spritestemp As New List(Of SpriteInfo)



        'false = blank
        'true = sprite
        Dim top As Integer
        Dim ToFind As Boolean = False
        For j = 0 To b.Height - 1
            If (isLineEmpty(b, j)) Then
                'blank
                If ToFind = False Then
                    spritestemp.Add(New SpriteInfo(top, j - top))
                    ToFind = True
                End If
            Else
                'sprite
                If ToFind Then
                    top = j
                    ToFind = False
                End If
            End If
        Next



        Dim left As Integer
        For Each s As SpriteInfo In spritestemp
            For j = 0 To b.Width - 1
                If (isColumnEmpty(b, j, s.top, s.top + s.y)) Then
                    'blank
                    If ToFind = False Then
                        sprites.Add(New SpriteInfo(s.top, s.y, left, j))
                        s.left = left
                        s.x = left - s.x
                        ToFind = True
                    End If
                Else
                    'sprite
                    If ToFind Then
                        left = j
                        ToFind = False
                    End If
                End If
            Next
        Next

        For Each s As SpriteInfo In sprites
            RichTextBox1.Text &= s.left() & ";" & s.top() - 2 & ";" & s.x() - 1 & ";" & s.y() + 2 & vbNewLine
        Next


    End Sub

    Function isLineEmpty(ByVal b As Bitmap, ByVal line As Integer)
        For k = 0 To b.Width - 1
            If (0 <> b.GetPixel(k, line).A) Then
                Return False
            End If
        Next
        Return True
    End Function

    Function isColumnEmpty(ByVal b As Bitmap, ByVal col As Integer, ByVal ymin As Integer, ByVal ymax As Integer)
        For k = ymin To ymax
            If (0 <> b.GetPixel(col, k).A) Then
                Return False
            End If
        Next
        Return True
    End Function


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
    End Sub
End Class
