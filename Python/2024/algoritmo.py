def bubble(arr):
  print("Bubble: ")
  n = len(arr)
  for i in range (n):
    for j in range(n-i-1):
      if(arr[j]>arr[j+1]):
        arr[j],arr[j+1] = arr[j+1], arr[j]
  print(arr)


def insertionSort(arr):
  print("InsertionSort: ")
  n = len(arr)
  for i in range(1,n):
    j = i
    while j > 0 and arr[j] < arr[j-1]:
      arr[j], arr[j-1] = arr[j-1], arr[j]
      j = j-1
  print(arr)

def main():
  arr = [4,3,7,5,9,6,1,8]
  bubble(arr)

main()