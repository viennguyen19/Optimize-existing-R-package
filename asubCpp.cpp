#include <Rcpp.h>
using namespace Rcpp;

std::string getAStringNumeric(Nullable<NumericVector> vec) {
    if(vec.isNotNull()) {
		NumericVector vector(vec);
		std::string res = "c(";
		for (int i = 0; i < vector.length(); i++) {
			std::ostringstream strs;
			strs << vector[i];
			std::string str = strs.str();
			res.append(str);

			if(i < vector.length() - 1) {
				res.append(", ");
			}
		}
		res.append(")");
		return res;
	}
	else {
		return "";
	}
}


std::string getAStringString(Nullable<StringVector> vec) {
    if(vec.isNotNull()) {
		StringVector vector(vec);
		std::string res = "c(";
		for (int i = 0; i < vector.length(); i++) {
			std::ostringstream strs;
			strs << vector[i];
			std::string str = strs.str();
			res.append("\"");
			res.append(str);
			res.append("\"");

			if(i < vector.length() - 1) {
				res.append(", ");
			}
		}
		res.append(")");
		return res;
	}
	else {
		return "";
	}
}

// [[Rcpp::export]]
std::string asubCpp(List idx, int numDims, NumericVector dims, bool drop, bool showDrop) {

    std::string outString = "x[";
	dims.sort();

    //outString.append("1");
    int counter = 0;
    for (int i = 0; i < numDims; i++) {
        if (dims[counter] - 1 == i) {
			std::string idxVal = "";
            if (is<StringVector>(idx[counter])) {
                idxVal = getAStringString(idx[counter]);
            } else {
                idxVal = getAStringNumeric(idx[counter]);
            }
            outString.append(idxVal);

            counter++;
        }
        outString.append(",");

        //outString.append("1,");
    }
    if (numDims > 0) {
        outString.resize (outString.size () - 1); //remove final comma
    }

    if (showDrop) {
        if (drop) {
            outString.append(", drop=TRUE]");
        } else {
            outString.append(", drop=FALSE]");
        }
    } else {
        outString.append("]");
    }
    return outString;
}
