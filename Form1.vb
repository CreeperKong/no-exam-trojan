Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        End
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        MessageBox.Show("后悔了是吧？没门！", "faq", MessageBoxButtons.OK, MessageBoxIcon.Error)
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub bgm()
        My.Computer.Audio.Play(My.Resources.Resource1.bgm, AudioPlayMode.BackgroundLoop)
    End Sub
End Class
