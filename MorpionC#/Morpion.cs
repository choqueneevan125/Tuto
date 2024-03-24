using System;

namespace Morpion
{
    class Program
    {
        static char[] board = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // Le plateau de jeu
        static char currentPlayer = 'X'; // Joueur actuel
        static bool gameOver = false; // Indique si le jeu est terminé

        static void Main(string[] args)
        {
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

        static void PrintBoard()
        {
            // Affichage du plateau de jeu
            Console.Clear();
            Console.WriteLine($" {board[0]} | {board[1]} | {board[2]} ");
            Console.WriteLine("---|---|---");
            Console.WriteLine($" {board[3]} | {board[4]} | {board[5]} ");
            Console.WriteLine("---|---|---");
            Console.WriteLine($" {board[6]} | {board[7]} | {board[8]} ");
        }

        static void PlayTurn()
        {
            // Le joueur choisit une case où placer son symbole
            int choice;
            do
            {
                Console.WriteLine($"Joueur {currentPlayer}, veuillez choisir un nombre (1-9) :");
                choice = int.Parse(Console.ReadLine()) - 1;
            } while (choice < 0 || choice >= 9 || !char.IsDigit(board[choice]));

            // Place le symbole du joueur sur la case choisie
            board[choice] = currentPlayer;
        }

        static void CheckForWin()
        {
            // Vérifie si un joueur a gagné
            if ((board[0] == currentPlayer && board[1] == currentPlayer && board[2] == currentPlayer) ||
                (board[3] == currentPlayer && board[4] == currentPlayer && board[5] == currentPlayer) ||
                (board[6] == currentPlayer && board[7] == currentPlayer && board[8] == currentPlayer) ||
                (board[0] == currentPlayer && board[3] == currentPlayer && board[6] == currentPlayer) ||
                (board[1] == currentPlayer && board[4] == currentPlayer && board[7] == currentPlayer) ||
                (board[2] == currentPlayer && board[5] == currentPlayer && board[8] == currentPlayer) ||
                (board[0] == currentPlayer && board[4] == currentPlayer && board[8] == currentPlayer) ||
                (board[2] == currentPlayer && board[4] == currentPlayer && board[6] == currentPlayer))
            {
                Console.WriteLine($"Le joueur {currentPlayer} a gagné !");
                gameOver = true;
                return;
            }

            // Vérifie s'il n'y a plus de cases vides (match nul)
            if (Array.TrueForAll(board, c => !char.IsDigit(c)))
            {
                Console.WriteLine("Match nul !");
                gameOver = true;
                return;
            }
        }

        static void SwitchPlayer()
        {
            // Change de joueur
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}
