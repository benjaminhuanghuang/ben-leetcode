/*
2353. Design a Food Rating System

https://leetcode.com/problems/design-a-food-rating-system/
*/

class FoodRatings {
  private foodRatings: Map<string, { rating: number; cuisine: string }>;
  private cuisineToFoods: Map<string, Set<string>>;
  private foodToCuisine: Map<string, string>;
  private foodToRating: Map<string, number>;

  constructor(foods: string[], cuisines: string[], ratings: number[]) {
    this.foodRatings = new Map();
    this.cuisineToFoods = new Map();
    this.foodToCuisine = new Map();
    this.foodToRating = new Map();

    for (let i = 0; i < foods.length; i++) {
      this.foodRatings.set(foods[i], {
        rating: ratings[i],
        cuisine: cuisines[i],
      });
      this.foodToCuisine.set(foods[i], cuisines[i]);
      this.foodToRating.set(foods[i], ratings[i]);

      if (!this.cuisineToFoods.has(cuisines[i])) {
        this.cuisineToFoods.set(cuisines[i], new Set());
      }
      this.cuisineToFoods.get(cuisines[i])!.add(foods[i]);
    }
  }

  changeRating(food: string, newRating: number): void {
    if (this.foodRatings.has(food)) {
      this.foodRatings.get(food)!.rating = newRating;
      this.foodToRating.set(food, newRating);
    }
  }

  highestRated(cuisine: string): string {
    if (!this.cuisineToFoods.has(cuisine)) return "";

    let maxRating = -Infinity;
    let highestRatedFood = "";

    for (const food of this.cuisineToFoods.get(cuisine)!) {
      const rating = this.foodToRating.get(food)!;
      if (
        rating > maxRating ||
        (rating === maxRating && food < highestRatedFood)
      ) {
        maxRating = rating;
        highestRatedFood = food;
      }
    }

    return highestRatedFood;
  }
}
