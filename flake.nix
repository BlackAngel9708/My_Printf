{
  description = "C Pool Day 12";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            glibc
            gcovr
            ltrace
            gnumake
            valgrind
            python311Packages.compiledb
            man-pages
            man-pages-posix
            aflplusplus
            gcc12
            criterion
          ];
        };

        formatter = pkgs.nixpkgs-fmt;
      });
}
