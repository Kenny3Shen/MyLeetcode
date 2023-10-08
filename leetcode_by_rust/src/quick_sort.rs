use rand::Rng;

fn main() {
    fn divide(nums: &mut Vec<i32>, left: usize, right: usize) -> usize {
        let pivot = nums[left];
        let mut l = left;
        let mut r = right;
        while l < r {
            while l < r && nums[r] >= pivot {
                r -= 1;
            }
            nums[l] = nums[r];
            while l < r && nums[l] <= pivot {
                l += 1;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        l
    }    
    fn conquer(nums: &mut Vec<i32>, left: usize, right: usize) {
        if left < right {
            let pivot = divide(nums, left, right);
            conquer(nums, left, pivot - 1);
            conquer(nums, pivot + 1, right);
        }
    }
    let mut nums = vec![Rng::gen_range(0..100); 100000000];
    let len = nums.len();
    conquer(&mut nums, 0, len - 1);
    println!("{:?}", nums)
}