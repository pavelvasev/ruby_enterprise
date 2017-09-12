# ruby_enterprise
Ruby Enterprise 1.8.7-2012.02 with patches to run on newer OSs. This is so legacy applications can update infrastructure.

You should sunset any application running Ruby 1.8.7 or upgrade it to use a more recent supported Ruby version.


## To install ruby-enterprise-2012.02

1. Clone this repo in the following manner:

  ```
  git clone https://github.com/pavelvasev/ruby_enterprise.git
  ```

1. Have installed packages:
  ```
  apt-get install build-essential patch zlib1g-dev libssl-dev libreadline-gplv2-dev git autoconf byacc flex
  ```

1. Use the installer and follow the directions.

  ```
  export CFLAGS="-fno-tree-dce -fno-optimize-sibling-calls"
  ./ruby-enterprise/installer --dont-install-useful-gems
  ```
  
  CFLAGS reason is https://github.com/rbenv/ruby-build/issues/488
