#Write a program to demonstrate the working of the decision tree based ID3 algorithm.

❖	ID3 Algorithm:
The ID3 algorithm uses entropy and information gain as measures to make decisions about feature selection and node splitting. It aims to create a decision tree that maximizes the information gain at each step, leading to a tree that can accurately classify new examples.
❖	Working:
1.	Input: The algorithm takes as input a dataset with labelled examples. Each example consists of a set of features and a corresponding class label.
2.	Select the root node: The first step is to select the root node of the decision tree. This is typically done by choosing the feature that provides the most information gain.
3.	Calculate information gain: For each feature, the algorithm calculates the information gain. Information gain measures how much the entropy of the dataset is reduced by splitting it based on a particular feature. The feature with the highest information gain is chosen as the root node.
4.	Split the dataset: The dataset is split into subsets based on the selected feature at the root node. Each subset contains examples that have the same value for the chosen feature.
5.	Repeat the process: The algorithm recursively repeats the above steps for each subset created in the previous step. It calculates the information gain for each remaining feature in the subset and chooses the one with the highest information gain as the next node in the tree. This process continues until a stopping criterion is reached.
6.	Stopping criterion: The stopping criterion could be reaching a maximum depth for the tree, having a minimum number of examples at a node, or when all examples in a subset belong to the same class.
7.	Assign class labels: Once the tree is built, class labels are assigned to the leaf nodes. This is done by taking the majority class of the examples in each leaf node.
8.	Predicting with the tree: To predict the class label for a new example, it traverses the decision tree based on the values of the features until it reaches a leaf node. The class label associated with that leaf node is then assigned as the predicted class label for the example.

❖	Dataset taken: IRIS Dataset.
-	This data sets consists of 3 different types of irises’ (Setosa, Versicolour, and Virginica) petal and sepal length, stored in a 150x4 numpy.ndarray.
-	The rows being the samples and the columns being: Sepal Length, Sepal Width, Petal Length and Petal Width.
-	No. of Rows: 150
-	No. of Columns: 4
