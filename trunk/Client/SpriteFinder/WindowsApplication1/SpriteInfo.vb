Public Class SpriteInfo


    Public _top As Integer

    Public _left As Integer

    Public _x As Integer

    Public _y As Integer


    Public Sub New(ByVal top As Integer, ByVal y As Integer)
        _top = top
        _y = y
    End Sub


    Public Sub New(ByVal top As Integer, ByVal y As Integer, ByVal left As Integer, ByVal x As Integer)
        _top = top
        _y = y
        _left = left
        _x = x
    End Sub

    Public Property x() As Integer
        Get
            Return _x
        End Get
        Set(ByVal newx As Integer)
            _x = newx
        End Set
    End Property

    Public Property y() As Integer
        Get
            Return _y
        End Get
        Set(ByVal newy As Integer)
            _y = newy
        End Set
    End Property

    Public Property top() As Integer
        Get
            Return _top
        End Get
        Set(ByVal newtop As Integer)
            _top = newtop
        End Set
    End Property

    Public Property left() As Integer
        Get
            Return _left
        End Get
        Set(ByVal newleft As Integer)
            _left = newleft
        End Set
    End Property

End Class
