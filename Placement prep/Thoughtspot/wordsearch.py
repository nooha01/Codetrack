# https://leetcode.com/problems/word-search/description/

class Solution:
	def exist(self, board: List[List[str]], word: str) -> bool:
			num_rows = len(board)  # for row number
			num_columns = len(board[0])  # for col number
			
			def dfs(row, col, count):
					if row < 0 or row == num_rows or col < 0 or col == num_columns:
							return False
					if board[row][col] != word[count] or board[row][col] == 'V':
							return False
					if count == len(word) - 1:
							return True
					
					cache = board[row][col]
					board[row][col] = 'V'
					
					result = (
							dfs(row + 1, col, count + 1)
							or dfs(row - 1, col, count + 1)
							or dfs(row, col + 1, count + 1)
							or dfs(row, col - 1, count + 1)
					)
					board[row][col] = cache
					
					return result
			
			return any(dfs(row, col, 0) for row in range(num_rows) for col in range(num_columns))
