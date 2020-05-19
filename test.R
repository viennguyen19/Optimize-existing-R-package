library(microbenchmark)
library(ggplot2)
library(abind)
library(abindcpp01)

# asub()

# small sized array

# x <- array(1:24,dim=c(2,3,4))
# 
# result <- microbenchmark(
#   abind=abind::asub(x, 1, 1),
#   abindccp01=abindcpp01::asub(x, 1, 1),
#   times=1000
# )
# result
# autoplot(result)


# medium sized array

# x <- array(1:(2**10), rep(2**3, times=6))
# x
# asub(x, 1, 1)
# 
# 
# result <- microbenchmark(
#   original=abind::asub(x, 1, 1),
#   ours=abindcpp01::asub(x, 1, 1),
#   times=1000
# )
# result
# autoplot(result)


# large array

# x <- array(1:(2**25), rep(2, times=25))
# asub(x, as.list(rep(1, 25)), 1:25)
# 
# result <- microbenchmark(
#   original=abind::asub(x, as.list(rep(1, 25)), as.vector(rep(1, 25))),
#   ours=abindcpp01::asub(x, as.list(rep(1, 25)), as.vector(rep(1, 25))),
#   times=100
# )
# result
# autoplot(result)


# acorn()

# small

# x <- array(1:24,dim=c(4,3,2),dimnames=rev(list(letters[1:2],LETTERS[1:3],letters[23:26])))
# abindcpp01::acorn(x, -3)
# 
# result <- microbenchmark(
#   'abindcpp01::acorn'=abindcpp01::acorn(x, -3),
#   'abind::acorn'=abind::acorn(x, -3),
#   times=1000
# )
# result
# autoplot(result)

# large, few args

# x <- array(1:(2**25), rep(2, times=25))
# 
# result <- microbenchmark(
#   'abindcpp01::acorn'=abindcpp01::acorn(x, 1, 2, -3),
#   'abind::acorn'=abind::acorn(x, 1, 2, -3),
#   times=100
# )
# result
# autoplot(result)

# large, more args

x <- array(1:(2**25), rep(2, times=25))

result <- microbenchmark(
  'abindcpp01::acorn'=abindcpp01::acorn(x, -3, 1, 2, 4, 5, 7, 9, -3, 1, 2, 4, 5, 7, 9, -3, 1, 2, 4, 5, 7, 9,-3, 1, 2, 4, 5, 7, 9,-3, 1, 2, 4, 5, 7, 9,-3, 1, 2, 4, 5, 7, 9),
  'abind::acorn'=abind::acorn(x, -3, 1, 2, 4, 5, 7, 9, -3, 1, 2, 4, 5, 7, 9, -3, 1, 2, 4, 5, 7, 9,-3, 1, 2, 4, 5, 7, 9,-3, 1, 2, 4, 5, 7, 9,-3, 1, 2, 4, 5, 7, 9),
  times=100
)
result
autoplot(result)