using System;

namespace Puissance4
{
    class Program
    {
        static char[,] board = new char[6, 7]; // Le plateau de jeu
        static char currentPlayer = 'X'; // Joueur actuel
        static bool gameOver = false; // Indique si le jeu est terminé

        static void Main(string[] args)
        {
            InitializeBoard();
            PrintBoard();

            while (!gameOver)
            {
                PlayTurn();
                PrintBoard();
                CheckForWin();
                SwitchPlayer();
            }

            Console.ReadLine(); // Garde la console ouverte à la fin
        }

        static void InitializeBoard()
        {
            // Initialisation du plateau de jeu avec des espaces vides
            for (int row = 0; row < 6; row++)
            {
                for (int col = 0; col < 7; col++)
                {
                    board[row, col] = ' ';
                }
            }
        }

        static void PrintBoard()
        {
            // Affichage du plateau de jeu
            Console.Clear();
            for (int row = 0; row < 6; row++)
            {
                for (int col = 0; col < 7; col++)
                {
                    Console.Write(board[row, col] + "|");
                }
                Console.WriteLine();
            }
            Console.WriteLine("---------------");
        }

        static void PlayTurn()
        {
            // Le joueur choisit une colonne où placer son jeton
            int col;
            do
            {
                Console.WriteLine($"Joueur {currentPlayer}, veuillez choisir une colonne (0-6) :");
                col = int.Parse(Console.ReadLine());
            } while (col < 0 || col >= 7 || board[0, col] != ' ');

            // Trouver la première case vide dans la colonne choisie et y placer le jeton du joueur
            for (int row = 5; row >= 0; row--)
            {
                if (board[row, col] == ' ')
                {
                    board[row, col] = currentPlayer;
                    break;
                }
            }
        }

        static void CheckForWin()
        {
            // Vérifie si un joueur a gagné
            for (int row = 0; row < 6; row++)
            {
                for (int col = 0; col < 4; col++)
                {
                    if (board[row, col] == currentPlayer &&
                        board[row, col + 1] == currentPlayer &&
                        board[row, col + 2] == currentPlayer &&
                        board[row, col + 3] == currentPlayer)
                    {
                        Console.WriteLine($"Le joueur {currentPlayer} a gagné !");
                        gameOver = true;
                        return;
                    }
                }
            }

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 7; col++)
                {
                    if (board[row, col] == currentPlayer &&
                        board[row + 1, col] == currentPlayer &&
                        board[row + 2, col] == currentPlayer &&
                        board[row + 3, col] == currentPlayer)
                    {
                        Console.WriteLine($"Le joueur {currentPlayer} a gagné !");
                        gameOver = true;
                        return;
                    }
                }
            }
        }

        static void SwitchPlayer()
        {
            // Changer de joueur
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}
